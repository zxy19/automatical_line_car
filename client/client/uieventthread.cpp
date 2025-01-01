#include "uieventthread.hpp"

//template<class T, class F>
//UiEventThread<T,F>::UiEventThread(T *target, F f){
//    this->toRunFunction = f;
//    this->widget = target;
//}
template<class T, class F>
void UiEventThread<T,F>::run(){
    ((this->widget).*(this->toRunFunction))();
}
