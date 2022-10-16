
#makefile BlogPart6
CC= g++ -std=c++11
BlogPart6: BlogPart6.o Area.o Post.o User.o SuperUser.o
	 	$(CC) BlogPart6.o Area.o Post.o User.o SuperUser.o -o BlogPart6

BlogPart6.o: BlogPart6.cpp
		 $(CC) -c BlogPart6.cpp

Area.o: Area.h Area.cpp
		 $(CC) -c Area.h
		 $(CC) -c Area.cpp

Post.o: Post.h Post.cpp
		 $(CC) -c Post.h
		 $(CC) -c Post.cpp

User.o: User.h User.cpp
		 $(CC) -c User.h
		 $(CC) -c User.cpp

SuperUser.o: SuperUser.h SuperUser.cpp
		 $(CC) -c SuperUser.h
		 $(CC) -c SuperUser.cpp

clean:
		rm -rf. *o BlogPart6

