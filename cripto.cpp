#include <iostream>
#include <cmath>
#include <fstream>


using namespace std;




using namespace std;

long long int M=1103515245;
long long int s;
long long int k;
long long int D=12345;
long long int p,base;
long long int a,b;



long long int power (long long int a, long long int b,long long MOD) {
    long long int ans=1ll;
    while(b) {
        if(b&1)ans=(ans*a)%MOD;
        a=(a*a)%MOD;
        b=b/2;
    }
    return ans;
    }


unsigned long int df(unsigned long int chave){
  
  unsigned long int key=0;
  
  long   long  int aux0=power(base,chave,p);
  
  //unsigned long int aux2=(unsigned long int ) aux0 % p;
  key=(unsigned long int ) aux0;
  
  return key;
} 

unsigned long   int getS(){
     long long int s;
  unsigned   long int S;
  s=(long unsigned int)df(b);
  long long int aux0=power(s,a,p);

  
  S=(unsigned  long int )aux0;
  
  
  return S;
  
}


unsigned char G(unsigned long int k) {
static unsigned char j = 0;
static unsigned long long int key = k;
if(j == 0){
key = M * key + D;
//cout<<key<<endl;
}
unsigned char z =(key >>j);
j = (j + 8) % 32;
return z;
}


int main(int argc, char **argv) {
   ifstream input(argv[1]); 
   ofstream out(argv[2]); 
  //string vetor1="abCdEa";
  string vetor;
  unsigned char xx;
  unsigned char r;
  unsigned char A;
  unsigned char B;
  unsigned char DH;
 unsigned int n=0;
  //pegando as chaves privadas base e p para o dif helmannn 
  
  input>>A;
  input>>a;
 
  input >> B;
  input >>b;
  //cout <<b<<endl;
  input >> DH;
  input >>DH;
  
 
  input >> p;
  //cout <<p<<endl;
  input >> base;
//  cout<<base<<endl;
  //pegando numero de mensagens
  input >> n; 
 
  
   //enviando A e B
   
   out<<"A->B: " <<df(a)<<endl;
   out<<"B->A: "<<df(b)<<endl;
   
      
   //calculo da chave publica
   s=getS();
   
   getline(input,vetor);
   //pegando numero de mensagens
   
   for(int i=0;i<n;i++){
      getline(input,vetor);
      //cout <<"vetor"<<vetor;
      if(i % 2 == 0){
  out<<"A->B: ";
  for(int k=0; k < vetor.length();k++){
    char xx=G(s);
    r=(unsigned char)vetor[k] ^ xx;
    out<<(int)r<<" ";
  }
  out<<endl;
      }else{
  out<<"B->A: ";
  for(int k=0; k < vetor.length();k++){
    char xx=G(s);
    r=(unsigned char)vetor[k] ^ xx;
    out<<(int)r<<" ";
    
  }
  out<<endl;
  
      }
     
  }
  
  
   input.close();
   out.close();
   //cout<<getS()<<endl;
   //unsigned char xx=G(s); 
   
  // unsigned char r=vetor[0] ^ xx;
   //cout<<(int)r<<endl; 
    //xx=G(s);
    // r=vetor[1] ^ xx;
 // cout<<(int)r<<endl;
}
