MAIN = main.cpp 

OBJS = dao.o cliente.o funcionario.o veiculo.o empresa.o global.o io_functions.o

COMPILER_FLAGS = -g -Wall -std=c++20

LINKER_FALGS = -lpqxx -lpq 

OBJ_NAME = Gerenciador_de_garagem



all : $(OBJS)
		$(CXX) main.cpp `pkg-config --cflags --libs gtk4`  $(OBJS) $(LINKER_FALGS) -o $(OBJ_NAME) `pkg-config --libs gtk4`

dao : $(OBJS)
		$(CXX) teste_dao.cpp $(OBJS) $(LINKER_FALGS) -o teste_dao_exec 
		
empresa : empresa.o dao.o 
		$(CXX) teste_empresa.cpp  empresa.o dao.o $(LINKER_FALGS) -o teste_empresa_exec

main.o: main_copy.cpp 
	$(CXX) -c main_copy.cpp 

dao.o: dao.cpp ../include/dao.h
	$(CXX) -c dao.cpp

cliente.o: cliente.cpp ../include/cliente.h
	$(CXX) -c cliente.cpp

funcionario.o: funcionario.cpp ../include/funcionario.h
	$(CXX) -c funcionario.cpp

veiculo.o: veiculo.cpp ../include/veiculo.h
	$(CXX) -c veiculo.cpp

empresa.o: empresa.cpp ../include/empresa.h
	$(CXX) -c empresa.cpp

global.o: global.cpp ../include/global.h
	$(CXX) -c global.cpp

io_functions.o: io_functions.cpp ../include/io_functions.h
	$(CXX) -c io_functions.cpp

