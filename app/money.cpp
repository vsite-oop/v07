#include "money.h"
#include <format>

namespace vsite::oop::v7
{
	std::string money::handleUnderflow()
	{
		return "Ne može se izvesti oduzimanje pre mali je broj";
	}
	std::string money::handleOverflow()
	{
		return "Ne može se izvesti dodavanje pre veliki je broj";
	}
	money::money(int e, int c) : eur(e), cnt(c) {

	};
	std::istream& operator>>(std::istream& s, money& m)
	{
		
		s >> m.eur >> m.cnt;
		return s;
	}
	money& money::operator +=(const money& other)
	{
		if (eur > std::numeric_limits<int>::max() - other.eur)
			throw std::overflow_error(handleOverflow());
		if (cnt + other.cnt >= 100)
		{
			cnt = (cnt + other.cnt) - 100;
			eur = eur + other.eur + 1;
		}
		else
		{
			cnt += other.cnt;
			eur += other.eur;
		}
		return *this;
	}
	money& money::operator -=(const money& other)
	{
		if (other.eur < 0)
		{
			if (eur < -(std::numeric_limits<int>::min() + other.eur))
				throw std::underflow_error(handleUnderflow());
			 if (cnt < other.cnt)
			 {
				cnt = (cnt + 100) - other.cnt;
				eur = eur + other.eur - 1;
			 }
			else
			{
				cnt -= other.cnt;
				eur += other.eur;
			}
			return *this;
		}
		else
		{
			if (eur < -(std::numeric_limits<int>::min() - other.eur))
				throw std::underflow_error(handleUnderflow());
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
	
	}
	std::ostream& operator <<(std::ostream& s, money m)
	{
		if (m.eur == 0)
			return s << std::format("{:02d} centi", m.cnt);
			
		else if (m.cnt == 0)
			return s << m.eur + " eura";
		else
			return s << std::format("{} eura {:02d} centi", m.eur, m.cnt);
	}
	std::string money::ispis()
	{
		if (cnt == 0)
			return std::format("{} eura", eur);
		else if (eur == 0)
			return std::format("{:02d} centi", cnt);
		else
			return std::format("{} eura {:02d} centi", eur, cnt);
	}
	int money::e() { return eur; }
	int money::c() { return cnt; }
}