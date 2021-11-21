#ifndef DIV_HPP
#define DIV_HPP


#include "base.hpp"
#include <string>

using namespace std;

class Div: public Base{
	private:
		double value;
		Base* left;
		Base* right;
	public:
		Div(Base* a, Base* b){
			if(b->evaluate() == 0){
				value = 0;
			} else {
				value = a->evaluate() / b->evaluate();
			} 
			this->left = a; 
			this->right = b;
		}
		virtual double evaluate() {return value;}
		virtual string stringify() {
			if(right->evaluate() == 0){
				return "Undefined";
			}
			return "(" + left->stringify() + "/" +  right->stringify() + ")";
		}
};

#endif
