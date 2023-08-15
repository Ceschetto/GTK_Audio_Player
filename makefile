
OBJECTS = obj/gtk_interface.o obj/file_manager.o
CFLAGS = `pkg-config --cflags gtk4` -Werror -Wall
CLIBS = `pkg-config --cflags --libs gtk4` 

output : clean $(OBJECTS)

	gcc src/main.c $(CFLAGS)  -o bin/main $(OBJECTS) $(CLIBS)


obj/gtk_interface.o: 
	gcc -c src/gtk_interface.c  $(CFLAGS) -o obj/gtk_interface.o  $(CLIBS)

obj/file_manager.o:
	gcc -c src/file_manager.c $(CFLAGS) -o obj/file_manager.o $(CLIBS)



clean: 
	rm -f $(OBJECTS)
	rm -f bin/*





run:
	clear
	./bin/main

