#include "Functionality.h"

    auto fn = [](ArrayContainer &data)->bool{
    if(data.empty()){
        return false;
    }
    else{
        return true;
    }
};

int main(){
    ArrayContainer data;
    ListContainer result;

    CreateObject(data);

 
    ListContainer res = ReturnInstancesIfPredicateSatisfies(data,fn);
    for(auto &d : res){
        std::cout<<*d<<"\n";
    }



    int ans = countwhoseChassesLengthabove(data);
    std::cout<<"countwhoseChasses Length above : "<<ans<<"\n";


    std::optional<int> as1= topspeedWhoseCardIdMatches(data,"101");
    std::cout<<as1.value()<<"\n";

    bool ans1= IfPlateformTypeIsPureEv(data);
    std::cout<<ans1<<"\n";

}