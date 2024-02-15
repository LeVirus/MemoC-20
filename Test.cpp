#pragma once
// Global module fragment where #includes can happen
// module;
// first thing after the Global module fragment must be a module command
export module foo;
//les import doivent être impérativement positionné aprés le "module;"
//import iostream;

export class Gege
{
public:
    Gege();
    ~Gege();
    void helloworld();
};
//export multiple elements
// export {
//     void func();
//     void func(int);
// }; //!!Point virgule!!


//Pour les headers ajouter les preproc suivant:
// #ifndef _HEADER_
// #define _HEADER_

// constexpr int life = 42;

// #endif
