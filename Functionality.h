#ifndef FUNCTIONALITY_H
#define FUNCTIONALITY_H

#include "EvCar.h"
#include <memory>
#include <functional>
#include <vector>
#include <list>
#include <array>
#include <algorithm>
#include <numeric>

using EvCarPointer  = std::shared_ptr<EvCar>;
using ArrayContainer = std::array<EvCarPointer,3>;
using ListContainer = std::list<EvCarPointer>;

void CreateObject(ArrayContainer& data);

ListContainer firstNInstances(ArrayContainer& data , int n);

int countwhoseChassesLengthabove(ArrayContainer& data);

std::optional<int>topspeedWhoseCardIdMatches(ArrayContainer& data , std::string id);

ListContainer ReturnInstancesIfPredicateSatisfies(ArrayContainer& data,std::function<bool(ArrayContainer& data)> fn);

bool IfPlateformTypeIsPureEv(ArrayContainer& data);


#endif // FUNCTIONALITY_H