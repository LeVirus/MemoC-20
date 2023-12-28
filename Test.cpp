
// Global module fragment where #includes can happen
// module;
// first thing after the Global module fragment must be a module command
export module foo;

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
// }
