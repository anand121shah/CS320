class pickups
{
private:
	bool isComplete;
public:
	pickups(){ isComplete = false };
	~pickups();
};

class skill : public pickups
{
private:
	bool analyze, creative, critical;
public:
	skill(){analyze = 0; creative = 0; critical = 0;};
	~skill();
};

class connection : public pickups
{
private:
	bool school, workplace, family;
public:
	connection(school = 0; workplace = 0; family = 0;);
	~connection();
};

class funding : public pickups
{
private:
	bool personal, heritage, credit;
public:
	funding(personal = 0; heritage = 0; credit = 0;);
	~funding();
};

