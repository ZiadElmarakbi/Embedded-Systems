
// Eng. Ziad Mohamed Elbendary _ 

#include <stdint.h> // AUTOSAR defined typedef convention.  

void reset_handler(void);
void NMI_handler(void) __attribute__((weak, alias ("default_handler")));;
void H_fault_handler(void)__attribute__((weak, alias ("default_handler")));;
void NM_fault_handler(void)__attribute__((weak, alias ("default_handler")));;
void Bus_fault(void)__attribute__((weak, alias ("default_handler")));;
void Usage_fault_handler(void)__attribute__((weak, alias ("default_handler")));;

extern int main(void); 
extern uint32_t stack_top;
extern uint32_t _E_Text_ ;
extern uint32_t _S_data_ ;
extern uint32_t _E_data_ ;
extern uint32_t _S_bss_ ;
extern uint32_t _E_bss_ ;

// Aliased Function (Unifiable Function)
void default_handler (){
	reset_handler();
}

uint32_t vectors[]__attribute__((section(".vectors"))) = {

	(uint32_t) &stack_top,
	(uint32_t) &reset_handler, 
	(uint32_t) &NMI_handler,
	(uint32_t) &NM_fault_handler,
	(uint32_t) &H_fault_handler,
	(uint32_t) &Bus_fault,
	(uint32_t) &Usage_fault_handler

	};

// Send byte by byte from ROM to RAM for .data section

void reset_handler(void){

uint32_t Data_Size = (uint8_t*)&_E_data_ - (uint8_t*)&_S_data_;
uint8_t* P_dest = (uint8_t*)&_S_data_;
uint8_t* P_src = (uint8_t*)&_E_Text_;
uint32_t i; 

for(i = 0; i < Data_Size; i++){

*((uint8_t*)P_dest++) = *((uint8_t*)P_src++);

} 

// Initialize the .bss section with zeros
uint32_t bss_size = (uint8_t*)&_E_bss_ - (uint8_t*) &_S_bss_;
P_dest = (uint8_t*)&_S_bss_;

for(i = 0; i<bss_size; i++){

	*((uint8_t*)P_dest++) = (uint8_t)0;

}
	main();
}