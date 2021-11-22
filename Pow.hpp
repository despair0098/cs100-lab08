#ifndef POW_HPP
#define POW_HPP


#include "base.hpp"
#include <string>
#include "math.h"

using namespace std;

class Pow: public Base{
	private:
		double value;
		Base* left;
		Base* right;
	public:
		Pow(Base* a, Base* b){value = pow(a->evaluate(),b->evaluate()); this->left = a; this->right = b;}
		virtual double evaluate() {return value;}
		virtual string stringify() {return "(" + left->stringify() + " ** " +  right->stringify() + ")";}
		virtual int number_of_children(){return 2;}
        virtual Base* get_child(int i){
            if(i == 0){
				return left;
			} else if (i == 2){
				return right;
			} else {
				return nullptr;
			}
        }
        virtual void accept(Visitor* visitor, int index){
            if(index == 0){
				visitor->visit_pow_begin(this);
			} else if(index == 1){
				visitor->visit_pow_middle(this);
			} else if(index == 2){
				visitor->visit_pow_end(this);
			}
        }
};

#endif
