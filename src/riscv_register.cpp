// Author: Sebastian Zanker

#include "riscv_register.h"


riscv_register::riscv_register() :
	used_as_src(0), used_as_dest(0)
{

}


void riscv_register::inc_src()
{
	used_as_src++;
}


void riscv_register::inc_dest()
{
	used_as_dest++;
}


int riscv_register::get_statistics(unsigned int& used_as_src, unsigned int& used_as_dest)
{
	used_as_src = this->used_as_src;
	used_as_dest = this->used_as_dest;
	return 0;
}
