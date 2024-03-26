#include <iostream>
using namespace std;

//对char和int类型的数组进行排序

//打印函数
template<class T>
void PrintArray(T *arr,int len){
    for(int i=0;i<len;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

//排序函数
template <class T>
void BubbleSort(T *arr,int len){
    for(int i=0;i<len;i++){
        for(int j=i+1;j<len;j++){
            //从大到小排序
            if(arr[i]<arr[j]){
                T tmp=arr[i];
                arr[i]=arr[j];
                arr[j]=tmp;
            }
        }
    }
}

int main(){
    int arr[]={2,6,1,8,9,2};
    int len=sizeof(arr)/sizeof(int);

    cout<<"排序前:"<<endl;
    PrintArray(arr,len);

    cout<<"排序后:"<<endl;
    BubbleSort(arr,len);
    PrintArray(arr,len);

    cout<<"--------------------"<<endl;

    char ch[]={'a','c','b','p','t'};
    len=sizeof(ch)/sizeof(char);

    cout<<"排序前:"<<endl;
    PrintArray(ch,len);
    cout<<"排序后:"<<endl;
    BubbleSort(ch,len);
    PrintArray(ch,len);

    return 0;
}