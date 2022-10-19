/* Linker_Script Cortex M3
Eng. Ziad Elmarakbi
*/

MEMORY
{
flash(rx) : ORIGIN = 0x08000000, LENGTH = 128k
sram(rwx) : ORIGIN = 0x20000000, LENGTH = 20k
}


SECTIONS
{

.text : {

	*(.vectors*)
	*(.text*)
	*(.rodata)
	_E_Text_ = . ;
}> flash

.data : {

	_S_data_ = . ;
	*(.data)
	_E_data_ = . ;

}> sram AT> flash

.bss : {

	_S_bss_ = . ;
	*(.bss)
	_E_bss_ = . ;

	. = . + 0x1000;
	stack_top = . ;

}> sram

}
