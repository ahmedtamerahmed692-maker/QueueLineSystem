#pragma once
#pragma warning(disable : 4996)
#include <iostream>
#include <string>
#include <queue>
#include <stack>
using namespace std;

class clsQueueLine
{
public:
    class clsTicket
    {
    private:
        short _Number = 0;
        string _Prefix;
        string _TicketTime;
        short _WaitingClients = 0;
        short _AverageServeTime = 0;

        string GetSystemDateTimeString()
        {
            time_t t = time(0);
            tm* now = localtime(&t);

            short Day = now->tm_mday;
            short Month = now->tm_mon + 1;
            short Year = now->tm_year + 1900;
            short Hour = now->tm_hour;
            short Minute = now->tm_min;
            short Second = now->tm_sec;

            return (to_string(Day) + "/" + to_string(Month) + "/"
                + to_string(Year) + " - "
                + to_string(Hour) + ":" + to_string(Minute)
                + ":" + to_string(Second));
        }

    public:
        clsTicket(string Prefix, short Number, short WaitingClients, short AverageServeTime)
        {
            _Number = Number;
            _Prefix = Prefix;
            _WaitingClients = WaitingClients;
            _AverageServeTime = AverageServeTime;
            _TicketTime = GetSystemDateTimeString();
        }

        string Prefix() { return _Prefix; }
        short Number() { return _Number; }
        string FullNumber() { return _Prefix + to_string(_Number); }
        string TicketTime() { return _TicketTime; }
        short WaitingClients() { return _WaitingClients; }

        short ExpectedServeTime()
        {
            return _AverageServeTime * _WaitingClients;
        }

        void Print()
        {
            cout << "\n\t\t\t  _________________________\n";
            cout << "\t\t\t\t  " << FullNumber() << "\n";
            cout << "\t\t\t  " << _TicketTime << "\n";
            cout << "\t\t\t  Waiting Clients: " << _WaitingClients << "\n";
            cout << "\t\t\t  Expected Serve Time: " << ExpectedServeTime() << " Min.\n";
            cout << "\t\t\t  _________________________\n";
        }
    };

private:
	queue <clsTicket> Servies; 
	string _Prefix;
	int _AverageServeTime;
	int _TotalTickets;

public:
	clsQueueLine(string Prefix, int AverageServeTime)
	{
		_Prefix = Prefix;
		_AverageServeTime = AverageServeTime;
		_TotalTickets = 0; 
	}

    void IssueTicket()
    {
       _TotalTickets++;
       clsTicket NewTicket(_Prefix, _TotalTickets, Servies.size(), _AverageServeTime);
       Servies.push(NewTicket);
    }

    short WaitingClients()
    {
        return Servies.size();
    }

    short ServedClients()
    {
        return _TotalTickets - Servies.size();
    }

    void ServeNextClient()
    {
        if (!Servies.empty())
        {
            Servies.pop(); 
        }
    }

    void PrintInfo()
    {
        cout << "\n\t\t\t  _________________________\n";
        cout << "\t\t\t\t  Queue Info\n";
        cout << "\t\t\t  _________________________\n";
        cout << "\t\t\t  Prefix             = " << _Prefix << "\n";
        cout << "\t\t\t  Served Clients     = " << ServedClients() << "\n";
        cout << "\t\t\t  Waiting Clients    = " << WaitingClients() << "\n";
        cout << "\t\t\t  Average Serve Time = " << _AverageServeTime << "\n";
        cout << "\t\t\t  _________________________\n";
    }

    void PrintTicketsLineLTR()
    {
        queue<clsTicket> TempQueue = Servies;
        cout << "\n\t\tTickets: ";
        while (!TempQueue.empty())
        {
            cout << TempQueue.front().FullNumber();
            TempQueue.pop();
            if (!TempQueue.empty())
            {
                cout << " --> ";
            }
        }
        cout << "\n";
    }

    void PrintTicketsLineRTL()
    {
        queue<clsTicket> TempQueue = Servies;
        stack<clsTicket> TempStack;
        while (!TempQueue.empty())
        {
            TempStack.push(TempQueue.front());
            TempQueue.pop();
        }
        cout << "\n\t\tTickets: ";
        while (!TempStack.empty())
        {
            cout << TempStack.top().FullNumber();
            TempStack.pop();
            if (!TempStack.empty())
            {
                cout << " <-- ";
            }
        }
        cout << "\n";
    }

    void PrintAllTickets()
    {
        queue<clsTicket> TempQueue = Servies;
        cout << "\n\t\t\t--- Tickets ---";
        if (TempQueue.empty())
        {
            cout << "\n\t\t\t--- No Tickets ---\n";
        }
        while (!TempQueue.empty())
        {
            TempQueue.front().Print();
            TempQueue.pop();
        }
    }
};
