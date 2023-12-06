#include "money.h"
#include <format>

namespace vsite::oop::v7
{
	money::money(int e, int c) : eur(e), cnt(c) {

	};
	std::istream& operator>>(std::istream& s, money& m)
	{
		
		s >> m.eur >> m.cnt;
		return s;
	}
	money& money::operator +=(const money& other)
	{
		eur += other.eur;
		cnt += other.cnt;
		if (cnt >= 100)
		{
			++eur;
			cnt -= 100;
		}
		return *this;
	}
	money& money::operator -=(const money& other)
	{
			if (cnt < other.cnt && eur > 0)
			{
				cnt = (cnt + 100) - other.cnt;
				eur = eur - other.eur - 1;
			}
			else if (eur < other.eur && cnt < other.cnt)
			{
				eur = -(other.eur - eur);
				cnt = other.cnt - cnt;
			}
			else if (eur < other.eur && cnt > other.cnt)
			{
				cnt = (other.cnt + 100) - cnt;
				eur = -(other.eur - eur - 1);
			}
			else
			{
				cnt -= other.cnt;
				eur -= other.eur;
			}
			return *this;	
	}
	std::ostream& operator <<(std::ostream& s,const money& m)
	{
		if (m.eur == 0)
			return s << std::format("{:02d} centi", m.cnt);

		else if (m.cnt == 0)
			return s << std::format("{} eura", m.eur);
		else if (m.cnt == 100)
			return s << std::format("{} eura",m.eur);
		else
			return s << std::format("{} eura {:02d} centi", m.eur, m.cnt);
	}
	int money::e() { return eur; }
	int money::c() { return cnt; }
}