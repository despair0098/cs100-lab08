#ifndef CONCRETEVISITOR_HPP
#define CONCRETEVISITOR_HPP


#include "visitor.hpp"
#include "iterator.hpp"
#include "Mult.hpp"
#include "Sub.hpp"
#include "Add.hpp"
#include "Div.hpp"
#include "Pow.hpp"
#include "op.hpp"
#include "Rand.hpp"

using namespace std;

class concreteVisitor : public Visitor {

    private:
        string latex = "";

    public: 
    concreteVisitor() {};
    ~concreteVisitor() = default;
    string PrintLateX(Base* ptr){
        concreteVisitor* visitor = new concreteVisitor();
        Iterator it = Iterator(ptr);
        while(!it.is_done()){
            it.current_node()->accept(visitor, it.current_index());
            it.next();
        }

        string latexFinal = visitor->getSides();
        delete visitor;
        return latexFinal;
    }

     // Nodes with no children are visited only once (index = 0)
        virtual void visit_op(Op* node){
            latex = node->stringify();
        };
        virtual void visit_rand(Rand* node){
            latex = node->stringify();
        };

        string getSides(){
            latex = "$" + latex;
            latex = latex + "$";
            return latex;
        }

        // Nodes with two children are visited three times.
        // index = 0 -> begin
        // index = 1 -> middle
        // index = 2 -> end
        virtual void visit_add_begin(Add* node){
            latex = latex + "{(";
        };
        virtual void visit_add_middle(Add* node){
            //Base* n1 = node->get_child(0);
            //Base* n2 = node->get_child(1);
            //latex = latex + n1->stringify() + "+" + n2->stringify();
            latex = latex + "+";
        };
        virtual void visit_add_end(Add* node){
            latex = latex + ")}";
        };
        virtual void visit_sub_begin(Sub* node){
            latex = latex + "{(";
        };
        virtual void visit_sub_middle(Sub* node){
            //Base* n1 = node->get_child(0);
            //Base* n2 = node->get_child(1);
            //latex = latex + n1->stringify() + "-" + n2->stringify();
            latex = latex + "-";  
        };
        virtual void visit_sub_end(Sub* node){
            latex = latex + ")}";
        };
        virtual void visit_mult_begin(Mult* node){
            latex = latex + "{(";
        };
        virtual void visit_mult_middle(Mult* node){
            //Base* n1 = node->get_child(0);
            //Base* n2 = node->get_child(1);
            //latex = latex + n1->stringify() + "\cdot" + n2->stringify();
            latex = latex + "\\cdot\\";
        };
        virtual void visit_mult_end(Mult* node){
            latex = latex + ")}";
        };
        virtual void visit_div_begin(Div* node){
            latex = latex + "\frac";
        };
        virtual void visit_div_middle(Div* node){
            Base* n = node->get_child(0);
            latex = latex + n->stringify();
        };
        virtual void visit_div_end(Div* node){
            Base* n = node->get_child(1);
            latex = latex + n->stringify();
        };
        virtual void visit_pow_begin(Pow* node){
            latex = latex + "{(";
        };
        virtual void visit_pow_middle(Pow* node){
            //Base* n1 = node->get_child(0);
            //Base* n2 = node->get_child(1);
            //latex = latex + n1->stringify() + "^" + n2->stringify();
            latex = latex + "^";
        };
        virtual void visit_pow_end(Pow* node){
            latex = latex + ")}";
        };
};

#endif