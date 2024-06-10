#include "Functionality.h"

void CreateObject(ArrayContainer &data)
{
    data[0] = std::make_shared<EvCar>("101", 20, PlatFormType::IC_BASED, 20.5f, 5, 200);
    data[1] = std::make_shared<EvCar>("102", 10, PlatFormType::PURE_EV, 22.5f, 5, 100);
    data[2] = std::make_shared<EvCar>("103", 50, PlatFormType::IC_BASED, 21.5f, 5, 150);

}  

ListContainer firstNInstances(ArrayContainer &data, int n)
{
    if(n<0 || n>data.size()){
        std::cout<<"N not valid";
    }

    ListContainer result;
    std::copy_n(
        data.begin(),
        n,
        std::inserter(result,result.begin())
    );
    return result;
}

int countwhoseChassesLengthabove(ArrayContainer &data)
{

    int ans =  std::count_if(
        data.begin(),
        data.end(),
        [](EvCarPointer &d){
            return d->chassisLength()>0.0f;
        }
    );
    return ans;

}

std::optional<int> topspeedWhoseCardIdMatches(ArrayContainer &data, std::string id)
{
    auto ptr = std::find_if(
        data.begin(),
        data.end(),
        [&](EvCarPointer &d){
            return d->carId()==id;
        }
    );
    int ans =  ptr->get()->topSpeed();
    if (!ans)
    {
        return std::nullopt;
    }
    else
    {
        return ans;
    }
}

ListContainer ReturnInstancesIfPredicateSatisfies(ArrayContainer &data, std::function<bool(ArrayContainer &data)> fn)
{
    ListContainer result;

   bool ans = fn(data);
   if(ans){
    std::for_each(
        data.begin(),
        data.end(),
        [&](EvCarPointer &d){
            result.push_back(d);
        }
    );
   }
   return result;

}

bool IfPlateformTypeIsPureEv(ArrayContainer &data)
{
    // auto ptr = std::any_of(
    //     data.begin(),
    //     data.end(),
    //     [](EvCarPointer &d){
    //         return d.get()->platform()==PlatFormType::PURE_EV;
    //     }
    // );
    // return ptr;

   bool flag;
    std::for_each(
        data.begin(),
        data.end(),
        [&](EvCarPointer& d){
            if(d.get()->platform()==PlatFormType::PURE_EV){
             flag = true;
            }
        }
    );
   return flag;
}
