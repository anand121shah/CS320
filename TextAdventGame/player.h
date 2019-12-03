class player
{
private:
	string fName, lName, nickName;
	char gender;
	bool skill, connection, money;
	int age;
	string birthday; // MM/DD/YY
public:
	player();
	~player();
	void set_fName(string n);
	void set_lName(string n);
	void set_nickName(sting n);
	void set_gender(char g);
	void set_skill(bool v);
	void set_connection(bool v);
	void set_money(bool v);
	void set_birthday(string b);

	string get_fname();
	string get_lname();
	string get_nickName();
	char get_gender();
	bool get_skill();
	bool get_connection();
	bool get_money();
	int get_age();
};