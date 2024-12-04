#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

class Member
{
public:
    string name;
    int id;
    string batch;
    string semester;
    string section;
    string codeforcesLink;
    string otherJudgeLink;
    string memberType;
    int contestsThisMonth;

    Member(string n, int i, string b, string s, string sec, string cfLink, string ojLink, string mType, int contests)
        : name(n), id(i), batch(b), semester(s), section(sec), codeforcesLink(cfLink), otherJudgeLink(ojLink), memberType(mType), contestsThisMonth(contests) {}

    Member() {}

    string toString() const
    {
        return name + "," + to_string(id) + "," + batch + "," + semester + "," + section + "," + codeforcesLink + "," + otherJudgeLink + "," + memberType + "," + to_string(contestsThisMonth);
    }
};

class Club
{
private:
    vector<Member> members;
    const string filename = "members.txt";

    void loadMembers()
    {
        ifstream infile(filename);
        if (!infile)
            return;
        string line;
        while (getline(infile, line))
        {
            istringstream iss(line);
            string name, batch, section, cfLink, ojLink, mType;
            int id, contests;
            string semester;
            getline(iss, name, ',');
            iss >> id;
            iss.ignore();
            getline(iss, batch, ',');
            getline(iss, semester, ',');
            getline(iss, section, ',');
            getline(iss, cfLink, ',');
            getline(iss, ojLink, ',');
            getline(iss, mType, ',');
            iss >> contests;
            members.emplace_back(name, id, batch, semester, section, cfLink, ojLink, mType, contests);
        }
    }

    void saveMembers()
    {
        ofstream outfile(filename);
        for (const auto &member : members)
        {
            outfile << member.toString() << "\n";
        }
    }

public:
    Club()
    {
        loadMembers();
    }

    ~Club()
    {
        saveMembers();
    }

    void addMember(const string &name, int id, const string &batch, string semester, const string &section, const string &cfLink, const string &ojLink, const string &memberType, int contests)
    {
        members.emplace_back(name, id, batch, semester, section, cfLink, ojLink, memberType, contests);
        cout << "--------------------------------------\n\n";
        cout << "Member added: " << name << " (ID: " << id << ")\n\n";
        cout << "--------------------------------------\n\n";
    }

    void removeMember(int id)
    {
        auto it = remove_if(members.begin(), members.end(), [id](const Member &m)
                            { return m.id == id; });
        if (it != members.end())
        {
            cout << "--------------------------------------\n\n";
            cout << "Member removed: " << it->name << " (ID: " << it->id << ")\n\n";
            members.erase(it, members.end());
            cout << "--------------------------------------\n\n";
        }
        else
        {
            cout << "--------------------------------------\n\n";
            cout << "Member not found with ID: " << id << "\n\n";
            cout << "--------------------------------------\n\n";
        }
    }

    void searchMember(int id)
    {
        for (const auto &member : members)
        {
            if (member.id == id)
            {
                cout << "\n-> Member found:\n";
                cout << "--------------------------------------\n\n";
                cout << "Name: " << member.name << "\n"
                     << "ID: " << member.id << "\n"
                     << "Batch: " << member.batch << "\n"
                     << "Semester: " << member.semester << "\n"
                     << "Section: " << member.section << "\n"
                     << "Codeforces Link: " << member.codeforcesLink << "\n"
                     << "Other Judge Link: " << member.otherJudgeLink << "\n"
                     << "Member Type: " << member.memberType << "\n"
                     << "Contests This Month: " << member.contestsThisMonth << "\n";
                cout << "\n--------------------------------------\n\n";
                return;
            }
        }
        cout << "--------------------------------------\n\n";
        cout << "Member not found with ID: " << id << "\n\n";
        cout << "--------------------------------------\n\n";
    }

    void updateMember(int id)
    {
        for (auto &member : members)
        {
            if (member.id == id)
            {
                cout << "\nEnter new details for the member (press Enter to skip and keep current value):\n\n";

                string input;
                cout << "Current Name: " << member.name << "\nNew Name: ";
                getline(cin, input);
                if (!input.empty())
                    member.name = input;

                cout << "Current Batch: " << member.batch << "\nNew Batch: ";
                getline(cin, input);
                if (!input.empty())
                    member.batch = input;

                cout << "Current Semester: " << member.semester << "\nNew Semester: ";
                getline(cin, input);
                if (!input.empty())
                    member.semester = input;

                cout << "Current Section: " << member.section << "\nNew Section: ";
                getline(cin, input);
                if (!input.empty())
                    member.section = input;

                cout << "Current Codeforces Link: " << member.codeforcesLink << "\nNew Codeforces Link: ";
                getline(cin, input);
                if (!input.empty())
                    member.codeforcesLink = input;

                cout << "Current Other Judge Link: " << member.otherJudgeLink << "\nNew Other Judge Link: ";
                getline(cin, input);
                if (!input.empty())
                    member.otherJudgeLink = input;

                cout << "Current Member Type: " << member.memberType << "\nNew Member Type: ";
                getline(cin, input);
                if (!input.empty())
                    member.memberType = input;

                cout << "Current Contests This Month: " << member.contestsThisMonth << "\nNew Contests This Month: ";
                getline(cin, input);
                if (!input.empty())
                    member.contestsThisMonth = stoi(input);

                cout << "--------------------------------------\n\n";
                cout << "Member details updated.\n\n";
                cout << "--------------------------------------\n\n";
                return;
            }
        }
        cout << "--------------------------------------\n\n";
        cout << "Member not found with ID: " << id << "\n\n";
        cout << "--------------------------------------\n\n";
    }

    void listMembers()
    {
        if (members.empty())
        {
            cout << "--------------------------------------\n\n";
            cout << "No members in the club.\n\n";
            cout << "--------------------------------------\n\n";
            return;
        }
        cout << "\n-> Members List:\n";
        int serialNumber = 1;
        for (const auto &member : members)
        {
            cout << "--------------------------------------\n\n";
            cout << serialNumber++ << "."; // Print the serial number
            cout << " Name: " << member.name << "\n"
                 << "   ID: " << member.id << "\n"
                 << "   Batch: " << member.batch << "\n"
                 << "   Semester: " << member.semester << "\n"
                 << "   Section: " << member.section << "\n"
                 << "   Codeforces Link: " << member.codeforcesLink << "\n"
                 << "   Other Judge Link: " << member.otherJudgeLink << "\n"
                 << "   Member Type: " << member.memberType << "\n"
                 << "   Contests This Month: " << member.contestsThisMonth << "\n";
            cout << "\n--------------------------------------\n\n";
        }
    }
};

int main()
{
    cout << "\n\t        \t\tWelcome To\n \t\t  Varendra University Programming Club\n";
    cout << " \t                    Management System\n";
    cout << "\t\t  ....................................\n";

    Club club;
    int choice;
    string name, batch, semester, section, cfLink, ojLink, memberType;
    int id, contests;

    while (true)
    {
        cout << R"(
         -----------------------------------------------------------
        |                        Club Menu                          |
        |-----------------------------------------------------------|
        |  1. Add Member           - Register a new member          |
        |                                                           |
        |  2. Remove Member        - Remove a member by ID          |
        |                                                           |
        |  3. Search Member        - Find a member by ID            |
        |                                                           |
        |  4. List Members         - Display all registered members |
        |                                                           |
        |  5. Update Member        - Modify member details          |
        |                                                           |
        |  6. Save Data & Exit     - Save members data and exit     |
         -----------------------------------------------------------
    )";
        // cout << "1. Add Member\n\n2. Remove Member\n\n3. Search Member\n\n4. List Members\n\n5. Update Member\n\n6. Save Data & Exit\n";
        cout << "\nChoose an option: ";
        cin >> choice;
        cin.ignore();
        switch (choice)
        {
        case 1:
            cout << "\nEnter name: ";
            getline(cin, name);
            cout << "Enter ID: ";
            cin >> id;
            cin.ignore();
            cout << "Enter batch: ";
            getline(cin, batch);
            cout << "Enter semester: ";
            getline(cin, semester);
            cout << "Enter section: ";
            getline(cin, section);
            cout << "Enter Codeforces link: ";
            getline(cin, cfLink);
            cout << "Enter other judge link: ";
            getline(cin, ojLink);
            cout << "Enter member type: ";
            getline(cin, memberType);
            cout << "Enter number of contests participated in this month: ";
            cin >> contests;
            club.addMember(name, id, batch, semester, section, cfLink, ojLink, memberType, contests);
            break;
        case 2:
            cout << "\nEnter ID of the member to remove: ";
            cin >> id;
            club.removeMember(id);
            break;
        case 3:
            cout << "\nEnter ID of the member to search: ";
            cin >> id;
            club.searchMember(id);
            break;
        case 4:
            club.listMembers();
            break;
        case 5:
            cout << "\nEnter ID of the member to update: ";
            cin >> id;
            cin.ignore();
            club.updateMember(id);
            break;
        case 6:
            return 0;
        default:
            cout << "\nInvalid option. Please try again.\n";
        }
    }
}
