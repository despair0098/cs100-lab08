#ifndef __CONCRETEVISITOR_HPP__
#define __CONCRETEVISITOR_HPP__

#include "visitor.hpp"
#include "base.hpp"
#include "iterator.hpp"
#include "Mult.hpp"
#include "Sub.hpp"
#include "Add.hpp"
#include "Div.hpp"
#include "Pow.hpp"
#include "op.hpp"
#include "Rand.hpp"
#include <string>


class concreteVisitor : public Visitor {

    private:
        string latex = "";

    public: 
    concreteVisitor() {};
    ~concreteVisitor() = default;

    std::string PrintLateX(Base* ptr){
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
            latex = "{" + node->stringify() + "}";
        };
        virtual void visit_rand(Rand* node){
            latex = "{" + node->stringify() + "}";
        };

    std::string getSides(){
        latex = "$" + latex + "$";
        return latex;
    }

        // Nodes with two children are visited three times.
        // index = 0 -> begin
        // index = 1 -> middle
        // index = 2 -> end
        virtual void visit_add_begin(Add* node){
            //Base* n1 = node->get_child(0);
            //latex = latex + "{(" + n1->stringify();
            latex = latex + "{(";
        };
        virtual void visit_add_middle(Add* node){
            latex = latex + "+";
        };
        virtual void visit_add_end(Add* node){
            //Base* n2 = node->get_child(2);
            //latex = latex + n2->stringify() + ")}";
            latex = latex + ")}";
        };
        virtual void visit_sub_begin(Sub* node){
            //Base* n1 = node->get_child(0);
            //latex = latex + "{(" + n1->stringify();
            latex = latex + "{(";
        };
        virtual void visit_sub_middle(Sub* node){
            latex = latex + "-";
        };
        virtual void visit_sub_end(Sub* node){
            //Base* n2 = node->get_child(2);
            //latex = latex + n2->stringify() + ")}";
            latex = latex + ")}";
        };
        virtual void visit_mult_begin(Mult* node){
            //Base* n1 = node->get_child(0);
            //latex = latex + "{(" + n1->stringify();
            latex = latex + "{(";
        };
        virtual void visit_mult_middle(Mult* node){
            latex = latex + "\\cdot\\";
        };
        virtual void visit_mult_end(Mult* node){
            //Base* n2 = node->get_child(2);
            //latex = latex + n2->stringify() + ")}";
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
            Base* n = node->get_child(2);
            latex = latex + n->stringify();
        };
        virtual void visit_pow_begin(Pow* node){
            //Base* n1 = node->get_child(0);
            //latex = latex + "{(" + n1->stringify();
            latex = latex + "{(";
        };
        virtual void visit_pow_middle(Pow* node){
            latex = latex +"^";
        };
        virtual void visit_pow_end(Pow* node){
           // Base* n2 = node->get_child(2);
           // latex = latex + n2->stringify() + ")}";
           latex = latex + ")}";
        };
};

#endif