#include <iostream>
#include "Playlist.h"

using namespace std;

int main(){

	//Miniquest 1 Test --- pass
	Playlist list1;
	
	Playlist::Song_Entry song1;
	song1.set_name("New York");
	song1.set_id(5);
	
	//cout << song1.get_name() << endl;
	//cout << song1.get_id() << endl;

	Playlist::Song_Entry song2;
	Playlist::Song_Entry song3 = Playlist::Song_Entry(3, "Dancing in the Moonlight");


	Playlist::Song_Entry song4 = Playlist::Song_Entry(4, "s4");
	Playlist::Song_Entry song5= Playlist::Song_Entry(5, "s5");
	Playlist::Song_Entry song6= Playlist::Song_Entry(6, "s6");
	Playlist::Song_Entry song7= Playlist::Song_Entry(7, "s7");
	Playlist::Song_Entry song8= Playlist::Song_Entry(8, "s8");
	Playlist::Song_Entry song9= Playlist::Song_Entry(9, "s9");
	Playlist::Song_Entry song10= Playlist::Song_Entry(10, "s10");
	Playlist::Song_Entry song11= Playlist::Song_Entry(11, "s11");
	Playlist::Song_Entry song12= Playlist::Song_Entry(12, "s12");
	Playlist::Song_Entry song13= Playlist::Song_Entry(13, "s13");
	Playlist::Song_Entry song14= Playlist::Song_Entry(14, "s14");
	Playlist::Song_Entry song15= Playlist::Song_Entry(15, "s15");
	Playlist::Song_Entry song16= Playlist::Song_Entry(16, "s16");
	Playlist::Song_Entry song17= Playlist::Song_Entry(17, "s17");
	Playlist::Song_Entry song18= Playlist::Song_Entry(18, "s18");
	Playlist::Song_Entry song19= Playlist::Song_Entry(19, "s19");
	Playlist::Song_Entry song20= Playlist::Song_Entry(20, "s20");
	Playlist::Song_Entry song21= Playlist::Song_Entry(21, "s21");
	Playlist::Song_Entry song22= Playlist::Song_Entry(22, "s22");
	Playlist::Song_Entry song23= Playlist::Song_Entry(23, "s23");
	Playlist::Song_Entry song24= Playlist::Song_Entry(24, "s24");
	Playlist::Song_Entry song25= Playlist::Song_Entry(25, "s25");
	Playlist::Song_Entry song26 = Playlist::Song_Entry(26, "s26");

	list1.insert_at_cursor(song1);
	list1.insert_at_cursor(song2);
	list1.insert_at_cursor(song3);
	list1.insert_at_cursor(song4);
	list1.insert_at_cursor(song5);
	list1.insert_at_cursor(song6);
	list1.insert_at_cursor(song7);
	list1.insert_at_cursor(song8);
	list1.insert_at_cursor(song9);
	list1.insert_at_cursor(song10);
	list1.insert_at_cursor(song11);
	list1.insert_at_cursor(song12);
	list1.insert_at_cursor(song13);
	list1.insert_at_cursor(song14);
	list1.insert_at_cursor(song15);
	list1.insert_at_cursor(song16);
	list1.insert_at_cursor(song17);
	list1.insert_at_cursor(song18);
	list1.insert_at_cursor(song19);
	list1.insert_at_cursor(song20);
	list1.push_back(song21);
	list1.push_back(song22);
	list1.push_back(song23);
	//list1.insert_at_cursor(song24);
	//list1.insert_at_cursor(song25);
	//list1.insert_at_cursor(song26);

	list1.advance_cursor();	
	list1.advance_cursor();
	list1.circular_advance_cursor();	

	cout << list1.to_string() << endl;

	

	return 0;
}
