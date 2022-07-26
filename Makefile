TARGET = Viewer.exe
INCLUDE = C:\SFML-2.5.1\include 
HEADERS = .\headers
LINK = C:\SFML-2.5.1\lib
LIBS = -lsfml-graphics -lsfml-window -lsfml-audio -lsfml-network -lsfml-system -mwindows
OBJS = main.o Debug.o Viewer.o RichText.o Fonts.o
CFLAGS = -L$(LINK) -I$(INCLUDE) -I$(HEADERS) -Wall
VPATH = .\src

$(TARGET) : $(OBJS)
	g++  $(CFLAGS) $(addprefix '.\objs\', $(OBJS)) -o .\$(TARGET) $(LIBS)

%.o : %.cc 
	g++ -c $(CFLAGS) $< -o .\objs\$@

%.o : %.cpp
	g++ -c $(CFLAGS) $< -o .\objs\$@

.PHONY: clean
clean :
	@del .\objs\*.o .\$(TARGET)