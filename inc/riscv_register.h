#pragma once

// Author: Sebastian Zanker
// Description: Models one register of the RISCV CPU core

class riscv_register
{
public:

	// Constructor
	riscv_register();

	void inc_src();
	void inc_dest();
	int get_statistics(unsigned int& used_as_src, unsigned int& used_as_dest);

private:
	unsigned int used_as_src;
	unsigned int used_as_dest;
};
