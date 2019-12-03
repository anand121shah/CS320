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
	skill(){analyze = false; creative = false; critical = false;};
	~skill();
};

class connection : public pickups
{
private:
	bool school, workplace, family;
public:
	connection(){school = false; workplace = false; family = false;};
	~connection();
};

class funding : public pickups
{
private:
	bool personal, heritage, credit;
public:
	funding(){personal = false; heritage = false; credit = false;};
	~funding();
};

