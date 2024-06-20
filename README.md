Ce code utilise le fichier test.json comme entrée et vérifie si il respecte bien le format JSON.

### Pour compiler :
```
mkdir build
cd build
cmake ..
make
```
### Pour éxécuter :
```
./JsonValidator
```

### Démo :
```bash
abder@abder-HP-Laptop:~/c++/JsonValidator/cmake-build$ ./JsonValidator 
Chaine de caractère à évaluer : 
{
    "prop1": {
        "prop_a": "abderrahmane"
    },
    "prop2":[
        123,
        22,
        122
    ]
}

>> Format valide
```
```bash
abder@abder-HP-Laptop:~/c++/JsonValidator/cmake-build$ ./JsonValidator 
Chaine de caractère à évaluer : 
{
    "prop1": {
        "prop_a": "abderrahmane"
    },
    
}

>> Format pas valide
```