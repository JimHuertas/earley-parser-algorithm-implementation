#ifndef EARLEY_STATE_H
#define EARLEY_STATE_H

#include "production.h"

class EarleyState{
private:
    string noTerminal;  
    Production* productionPtr;
    vector<EarleyState*> antecesor;
    int indexChart;
    int indexState;

public:
    EarleyState();
    EarleyState(string noTerminal, Production* product, EarleyState* antecesor, int indexChart, int indexState);
    ~EarleyState();
    bool isComplete();
    string nextChart();

    Production* getProduction(){ return productionPtr; }
    vector<EarleyState*>& getAntecesor(){ return antecesor; }
    int getIndexChart(){ return indexChart; }
    int getIndexState(){ return indexState; }
};

EarleyState::EarleyState(){
    productionPtr = nullptr;
}
EarleyState::EarleyState(string noTerminal, Production* product, EarleyState* antecesor, int indexChart, int indexState){
    this->noTerminal = noTerminal;
    this->productionPtr = product;
    this->antecesor.push_back(antecesor);
    this->indexChart = indexChart;
    this->indexState = indexState;
}

EarleyState::~EarleyState(){
}

bool EarleyState::isComplete(){
    if(indexChart == productionPtr->getProductions().size() )
        return true;
    return false;
}

string EarleyState::nextChart(){
    return productionPtr->getProductions().at(indexChart);
}


#endif
