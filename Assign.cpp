
#include <iostream>
#include "Assign.h"
#include "ShuntingYard.h"

#define VAR_INDEX 0
#define VALUE_INDEX 2

/**
 * Ctor.
 * @param params include the var name and his value.
 */
Assign::Assign(vector<string> params){
    this->var = params[VAR_INDEX];
    // get the string expression for futher Shunting Yard use
    for (int i = VALUE_INDEX; i < params.size(); i++) {
        this->value += params[i];
    }
}
//comment check
/**
 *
 * @return
 */
double Assign::execute() {
    ShuntingYard sy;
    // add to the symbol table
    data.setSymbolTable(this->var,
            sy.createExpression(this->value)->calculate());
    return 0;
}
