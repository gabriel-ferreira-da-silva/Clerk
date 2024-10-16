# Variáveis
CXX = g++
CXXFLAGS = -Iutils -Iobject -Iscenes -lGL -lGLU -lglut
OBJ_DIR = obj
SCENE =

# Lista de fontes e objetos
UTILS_SRCS = $(wildcard utils/*.cpp)
OBJECT_SRCS = $(wildcard object/*.cpp)
UTILS_OBJS = $(patsubst utils/%.cpp, $(OBJ_DIR)/%.o, $(UTILS_SRCS))
OBJECT_OBJS = $(patsubst object/%.cpp, $(OBJ_DIR)/%.o, $(OBJECT_SRCS))

# Regra padrão para compilar
all: $(SCENE)

# Compilar a cena escolhida
$(SCENE): $(UTILS_OBJS) $(OBJECT_OBJS)
	$(CXX) $(CXXFLAGS) $(UTILS_OBJS) $(OBJECT_OBJS) scenes/$(SCENE).cpp -o scenes/$(SCENE)

# Compilar os objetos .o de cada .cpp
$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Limpar arquivos compilados
clean:
	rm -rf $(OBJ_DIR) scenes/$(SCENE)
