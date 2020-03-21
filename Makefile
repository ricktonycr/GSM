CXX      := -g++
CXXFLAGS := `pkg-config gtkmm-3.0 --cflags --libs` `pkg-config glibmm-2.4 --cflags --libs` #-pedantic-errors -Wall -Wextra -Werror
LDFLAGS  := 
BUILD    := ./dist
OBJ_DIR  := $(BUILD)/objects
APP_DIR  := $(BUILD)/apps
TARGET   := gsm
INCLUDE  := -Isrc/include/
SRC      :=                   \
   $(wildcard src/*.cc)      \
   $(wildcard src/controller/*.cc)      \
   $(wildcard src/model/*.cc)      \

OBJECTS := $(SRC:%.cpp=$(OBJ_DIR)/%.o)

all: build $(APP_DIR)/$(TARGET)

$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) $(INCLUDE) -o $@ -c $<

$(APP_DIR)/$(TARGET): $(OBJECTS)
	@mkdir -p $(@D)
	$(CXX) $(INCLUDE) $(LDFLAGS) -o $(APP_DIR)/$(TARGET) $(OBJECTS) $(CXXFLAGS)

.PHONY: all build clean debug release

build:
	@mkdir -p $(APP_DIR)
	@mkdir -p $(OBJ_DIR)

debug: CXXFLAGS += -DDEBUG -g
debug: all

release: CXXFLAGS += -O2
release: all

clean:
	-@rm -rvf $(OBJ_DIR)/*
	-@rm -rvf $(APP_DIR)/*