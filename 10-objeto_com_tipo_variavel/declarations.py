def decl (name, typename):
    return f"virtual Var {name}({typename} arg2) const {'{'} return Undefined(); {'}'}"

if __name__ == "__main__":
    from sys import argv

    typenames = ["int", "double", "char", "bool", "std::string"]
    
    print(f"virtual Var sel_{argv[1]}(Undefined* arg1) const {'{'} return Undefined(); {'}'}")
    
    for d in map(lambda typename: decl(argv[1], typename), typenames):
        print(d)
    