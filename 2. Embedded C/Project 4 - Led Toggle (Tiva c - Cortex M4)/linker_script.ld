/* Linker_Script tiva C Cortex M4
Eng. Ziad Elmarakbi
*/

MEMORY
{
flash(rx) : ORIGIN = 0x00000000, LENGTH = 512M
sram(rwx) : ORIGIN = 0x20000000, LENGTH = 512M
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
}> sram

}
