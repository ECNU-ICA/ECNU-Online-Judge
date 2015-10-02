#include <string>
#include <cstdio>
using std::string;
#define nxL printf("\n")
struct CInteger
{
    string s;
    void print(void)
    {


        if(s[0] == '-')
        {
            printf("-");
        }
        for(string::size_type i=s.length()-1; i>0; --i )
        {
            printf("%c",s[i]);
        }
    }
    //³ýÈ¥¸ßÎ»0
    void DeleteUpperZero( void )
    {
        string::size_type i;
        for( i=s.length()-1; (s[i]=='0')&&(i>1); --i )
        {
            s.erase( i, 1 );
        }
        if( (i==1) && (s[1]=='0') )
        {
            s[0] = '+';
        }
        return;
    }
    //È¡¾ø¶ÔÖµ
	CInteger Abs( void ) const
    {
        CInteger c( *this );
        c.s[0] = '+';
        return c;
    }
    //È¡µÃÊý×Ö²»´ø·ûºÅ
	string AbsToString( void ) const
    {
        string str( s.substr( 1 ) );
        char   temp;
        for( string::size_type i=0,j=str.length()-1; i<j; ++i,--j )
        {
            temp = str[i];
            str[i] = str[j];
            str[j] = temp;
        }
        return str;
    }
    //È¡µÃÊý×ÖµÄ·ûºÅ
    string SignToString( void ) const
    {
        return s.substr( 0, 1 );
    }
    CInteger()
    {
        s+="+0";
    }
    CInteger(const CInteger &x)
    {
        s=x.s;
    }
    CInteger(int x)
    {
        *this = x;
    }
    CInteger(__int64 x)
    {
        *this = x;
    }
    CInteger(const string &str)
    {
        *this = str;
    }
    //¸ß¾«¶ÈÓë¸ß¾«¶ÈÔËËã
    CInteger operator=( int x )
    {
        if( x )
        {
            s = "+";
            if( x < 0 )
            {
                x = -x;
                s = "-";
            }
            while( x )
            {
                s += x % 10 + '0';
                x /= 10;
            }
        }
        else
        {
            s = "+0";
        }
        return *this;
    }
    //ÐèÒªDeleteUpperZero()
    CInteger operator=( const string & str )
    {
        if( ( str.find_first_not_of( "0123456789+-" ) != string::npos ) || ( str.find_first_of( "0123456789" ) == string::npos ) || ( str.length()<1 ) )
        {
            s = "+0";
        }
        else
        {
            s = str;
            if( (s[0]!='+') && (s[0]!='-') )
            {
                s.insert( 0, "+" );
            }
            char temp;
            for( string::size_type i=1,j=s.length()-1; i<j; ++i,--j )
            {
                temp = s[i];
                s[i] = s[j];
                s[j] = temp;
            }
        }
        DeleteUpperZero();
        return *this;
    }
    CInteger operator=(const CInteger &x )
    {
        s = x.s;
        return *this;
    }
    //ÐèÒªDeleteUpperZero()
    CInteger operator+(const CInteger &x ) const
    {
        CInteger c;
        string::size_type i;
        if( x.s[0] == s[0] )
        {
            if( s.length() > x.s.length() )
            {
                c.s = s + "0";
                for( i=x.s.length()-1; i>0; --i )
                {
                    c.s[i] += x.s[i] - '0';
                }
            }
            else
            {
                c.s = x.s + "0";
                for( i=s.length()-1; i>0; --i )
                {
                    c.s[i] += s[i] - '0';
                }
            }
            for( i=1; i<c.s.length(); ++i )
            {
                if( c.s[i] > '9' )
                {
                    c.s[i+1] += 1;
                    c.s[i]   -= 10;
                }
            }
            c.DeleteUpperZero();
            return c;
        }
        else
        {
            c.s    = x.s;
            c.s[0] = s[0];
            return *this - c;
        }
    }
    //ÐèÒªDeleteUpperZero()
    CInteger operator-(const CInteger &x ) const
    {
        CInteger c( x );
        string::size_type i;
        if( s[0] == x.s[0] )
        {
            if( this->CompareAbs( c ) < 0 )
            {
                c.s = x.s;
                c.s[0] = '-';
                for( i=s.length()-1; i>0; --i )
                {
                    c.s[i] -= s[i] - '0';
                }
            }
            else
            {
                c.s = s;
                c.s[0] = '+';
                for( i=x.s.length()-1; i>0; --i )
                {
                    c.s[i] -= x.s[i] - '0';
                }
            }
            for( i=1; i<c.s.length(); ++i )
            {
                if( c.s[i] < '0' )
                {
                    c.s[i]   += 10;
                    c.s[i+1] -= 1;
                }
            }
            c.DeleteUpperZero();
            return c;
        }
        else
        {
            c.s    = x.s;
            c.s[0] = s[0];
            return *this + c;
        }
    }
    //ÐèÒªDeleteUpperZero()
    CInteger operator*(const CInteger &x ) const
    {
        CInteger c;
        c.s = string( s.length()+x.s.length(), '0' );
        string::size_type i, j;
        int g;
        for( i=1; i<s.length(); ++i )
        {
            for( j=1; j<x.s.length(); ++j )
            {
                g = ( c.s[i+j-1] - '0' ) + ( s[i] - '0' ) * ( x.s[j] - '0' );
                c.s[i+j]   += g / 10;
                c.s[i+j-1]  = g % 10 + '0';
            }
        }
        if( s[0] == x.s[0] )
        {
            c.s[0] = '+';
        }
        else
        {
            c.s[0] = '-';
        }
        c.DeleteUpperZero();
        return c;
    }
    //ÐèÒª AbsDivAbs()
    CInteger operator/(const CInteger &x ) const
    {
        return this->AbsDivAbs( x );
    }
    //ÐèÒª AbsModAbs()
    CInteger operator%(const CInteger &x ) const
    {
        return this->AbsModAbs( x );
    }
    //ÐèÒªDeleteUpperZero() CompareAbs() Abs()
    CInteger AbsDivAbs(const CInteger &x ) const
    {
        int i = this->CompareAbs( x );
        if( i < 0 )
        {
            return CInteger( 0 );
        }
        if( i == 0 )
        {
            return CInteger( 1 );
        }
        CInteger c( string( "+1" ) + string( 1 + s.length() - x.s.length(), '0' ) );
        CInteger xabs = x.Abs(), thisabs = this->Abs();
        char j;
        for( i=c.s.length()-1; i>0; --i )
        {
            for( j='9'; j>='0'; --j )
            {
                c.s[i] = j;
                if( c * xabs <= thisabs )
                {
                    break;
                }
            }
        }
        c.DeleteUpperZero();
        return c;
    }
    //ÐèÒª AbsDivAbs()
    CInteger AbsModAbs(const CInteger &x ) const
    {
        return this->Abs() - this->AbsDivAbs( x ) * x.Abs();
    }
    // ´óÐ¡±È½ÏÐèÒªÓÃµ½¸Ãº¯Êý ÐèÒªCompareAbs()
    int Compare( const CInteger & x ) const
    {
        if( s[0] == x.s[0] )
        {
            if( s[0] == '+' )
            {
                return this->CompareAbs( x );
            }
            else
            {
                return -( this->CompareAbs( x ) );
            }
        }
        else
        {
            if( s[0] == '+' )
            {
                return 1;
            }
            return -1;
        }
    }
    // °´¾ø¶ÔÖµ´óÐ¡±È½Ï
    int CompareAbs( const CInteger & x ) const
    {
        if( s.length() > x.s.length() )
        {
            return 1;
        }
        if( s.length() < x.s.length() )
        {
            return -1;
        }
        for( string::size_type i=s.length()-1; i>0; --i )
        {
            if( s[i] > x.s[i] )
            {
                return 1;
            }
            if( s[i] < x.s[i] )
            {
                return -1;
            }
        }
        return 0;
    }
    //ÐèÒª Compare()
    int operator<( const CInteger & x ) const
    {
        return this->Compare( x ) < 0;
    }
    //ÐèÒª Compare()
    int operator==( const CInteger & x ) const
    {
        return this->Compare( x ) == 0;
    }
    //ÐèÒª Compare()
    int operator>( const CInteger & x ) const
    {
        return this->Compare( x ) > 0;
    }
    //ÐèÒª Compare()
    int operator<=( const CInteger & x ) const
    {
        return this->Compare( x ) < 1;
    }
    //ÐèÒª Compare()
    int operator>=( const CInteger & x ) const
    {
        return this->Compare( x ) > -1;
    }
};


#include <cstdio>
using namespace std;


int main()
{
    char num1[505];
    char num2[505];
    CInteger a, b, c;
    int cas;
    scanf("%d",&cas);
    while(cas--)
    {
        scanf("%s %s",num1,num2);
        string s1(num1);
        string s2(num2);
        a=s1;
        b=s2;
        (a*b).print();
        nxL;
    }


    return 0;
}//Parsed in 0.697 seconds
