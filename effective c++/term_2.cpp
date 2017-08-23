#include <string>

//条款2：尽量以const 、enum、inline代替define

//bad
#define ASPECT_RATIO 1.653
//better
const double AspectRatio = 1.653;


//bad
const char * const authorName = "Scott Meyar";
//better
const std::string authorName("Scott Meyar");


//bad 
#define NumTurns 5
//better
class GamePlayer
{
private:
	static const int NumTurn;
	enum {len = 5};
	int scores[len];
};
const int GamePlayer::NumTurn = 5;


//bad
#define CALL_WITH_MAX(a,b)  f((a)>(b)?(a):(b))
//better
template <typename T>
inline void callWithMax(T a, T b)
{
	f(a > b ? a : b);
}