#include "../../include/dao.h"
#include "../../include/empresa.h"

int main(){

    Dao* dao = new Dao("yourUser", "yourPassword", "yourHost", "yourPort", "DBname");

    Empresa* empresa = new Empresa(dao, "Garagem Teste");

    empresa->print();

    return 0;
}