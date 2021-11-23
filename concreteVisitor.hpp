#ifndef __CONCRETEVISITOR_HPP__
#define __CONCRETEVISITOR_HPP__

#include "base.hpp"
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
        std::string latex = "";

    public: 
    concreteVisitor() {};

    ~concreteVisitor() = default;

    string PrintLateX(Base* ptr){
    std::string PrintLateX(Base* ptr){
        concreteVisitor* visitor = new concreteVisitor();
        Iterator i = Iterator(ptr);
        while(!i.is_done()){
            i.current_node()->accept(visitor, i.current_index());
            i.next();
        }

        std::string latexFinal = visitor->getSides();
        delete visitor;
        return latexFinal;
    };

     // Nodes with no children are visited only once (index = 0)
        virtual void visit_op(Op* node){
            latex = latex + "{";
            latex = latex + node->stringify();
            latex = latex + "}";
        };
        virtual void visit_rand(Rand* node){
            latex = latex + "{";
            latex = latex + node->stringify();
            latex = latex + "}";    
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
            latex = latex + "{(";
        };
        virtual void visit_add_middle(Add* node){
            latex = latex + "+";
        };
        virtual void visit_add_end(Add* node){
            latex = latex + ")}";
        };
        virtual void visit_sub_begin(Sub* node){
            latex = latex + "{(";
        };
        virtual void visit_sub_middle(Sub* node){
            latex = latex + "-";
        };
        virtual void visit_sub_end(Sub* node){
            latex = latex + ")}";
        };
        virtual void visit_mult_begin(Mult* node){
            latex = latex + "{(";
        };
        virtual void visit_mult_middle(Mult* node){
            latex = latex + "\\cdot";
        };
        virtual void visit_mult_end(Mult* node){
            latex = latex + ")}";
        };
        virtual void visit_div_begin(Div* node){
            latex = latex + "{\\frac";
        };
        virtual void visit_div_middle(Div* node){
            
        };
        virtual void visit_div_end(Div* node){
            latex = latex + "}";
        };
        virtual void visit_pow_begin(Pow* node){
            latex = latex + "{(";
        };
        virtual void visit_pow_middle(Pow* node){
            latex = latex +"^";
        };
        virtual void visit_pow_end(Pow* node){
           latex = latex + ")}";
        };
};

#endif
