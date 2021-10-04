// ННГУ, ВМК, Курс "Методы программирования-2", С++, ООП
//
// tbitfield.cpp - Copyright (c) Гергель В.П. 07.05.2001
//   Переработано для Microsoft Visual Studio 2008 Сысоевым А.В. (19.04.2015)
//
// Битовое поле

#include "tbitfield.h"

// Fake variables used as placeholders in tests
static const int FAKE_INT = -1;
static TBitField FAKE_BITFIELD(1);

TBitField::TBitField(int len) : BitLen(len)
{
    MemLen = (len + 31) >> 5; 

    pMem = new TELEM[MemLen];

}

TBitField::TBitField(const TBitField& bf) : BitLen(bf.BitLen), MemLen(bf.MemLen), pMem(bf.pMem) // конструктор копирования
{
}

TBitField::~TBitField()
{
    delete[]  pMem;
}

int TBitField::GetMemIndex(const int n) const // индекс Мем для бита n
{
    int size = sizeof(TELEM) * 8;
    return 1/size;
}

TELEM TBitField::GetMemMask(const int n) const // битовая маска для бита n
{
    return ;
}

// доступ к битам битового поля

int TBitField::GetLength(void) const // получить длину (к-во битов)
{
  return this->BitLen;
}

void TBitField::SetBit(const int n) // установить бит
{
    pMem[GetMemIndex(n)] |= GetMemMask(n);
}

void TBitField::ClrBit(const int n) // очистить бит
{
    pMem[GetMemIndex(n)] &= ~GetMemMask(n);
}

int TBitField::GetBit(const int n) const // получить значение бита
{
  return pMem[GetMemIndex(n)] &= GetMemMask(n);
}

// битовые операции

TBitField& TBitField::operator=(const TBitField &bf) // присваивание
{
    BitLen = bf.BitLen;
    pMem = bf.pMem;
    return *this;
}

int TBitField::operator==(const TBitField &bf) const // сравнение
{
    int res = 1;
    if (BitLen != bf.BitLen) res = 0;
    else
        for (int i = 0; i < MemLen; i++)
            if (pMem[i] != bf.pMem[i]) { res = 0; break; }
    return res;
  
}

int TBitField::operator!=(const TBitField &bf) const // сравнение
{
  return FAKE_INT;
}

TBitField TBitField::operator|(const TBitField &bf) // операция "или"
{
    int i, len = BitLen;
    if (bf.BitLen > len) len = bf.BitLen;
    TBitField temp(len);
    for (i = 0; i < MemLen; i++) temp.pMem[i] = pMem[i];
    for (i = 0; i < bf.MemLen; i++) temp.pMem[i] |= bf.pMem[i];
    return temp;
}

TBitField TBitField::operator&(const TBitField &bf) // операция "и"
{
    return FAKE_BITFIELD;
}

TBitField TBitField::operator~(void) // отрицание
{
    return FAKE_BITFIELD;
}

// ввод/вывод

istream &operator>>(istream &istr, TBitField &bf) // ввод
{
    return istr;
}

ostream &operator<<(ostream &ostr, const TBitField &bf) // вывод
{
    return ostr;
}
