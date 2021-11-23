#ifndef SUB_HPP
#define SUB_HPP


#include "base.hpp"
#include <string>

using namespace std;

class Sub: public Base{
	private:
		double value;
		Base* left;
		Base* right;
	public:
		Sub(Base* a, Base* b){value = a->evaluate() - b->evaluate(); this->left = a; this->right = b;}
		virtual double evaluate() {return value;}
		virtual string stringify() {return "(" + left->stringify() + " - " +  right->stringify() + ")";}
		virtual int number_of_children(){return 2;}
        virtual Base* get_child(int i){
            if(i == 0){
				return left;
			} else if (i == 1){
				return right;
			} else {
				return nullptr;
			}
        }
        virtual void accept(Visitor* visitor, int index){
            if(index == 0){
				visitor->visit_sub_begin(this);
			} else if(index == 1){
				visitor->visit_sub_middle(this);
			} else if(index == 2){
				visitor->visit_sub_end(this);
			}
        }
};

#endif
