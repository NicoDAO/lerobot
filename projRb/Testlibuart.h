/*
 * Testlibuart.h
 *
 *  Created on: 1 sept. 2018
 *      Author: nicolas
 */

#ifndef SRC_TESTLIBUART_H_
#define SRC_TESTLIBUART_H_

#include "xparameters.h"
#include "xplatform_info.h"
#include "xuartps.h"
#include "xil_exception.h"
#include "xil_printf.h"

#ifdef XPAR_INTC_0_DEVICE_ID
#include "xintc.h"
#else
#include "xscugic.h"
#endif
/************************** Constant Definitions **************************/

/*
 * The following constants map to the XPAR parameters created in the
 * xparameters.h file. They are defined here such that a user can easily
 * change all the needed parameters in one place.
 */
#ifdef XPAR_INTC_0_DEVICE_ID
#define INTC		XIntc
#define UART_DEVICE_ID		XPAR_XUARTPS_0_DEVICE_ID
#define INTC_DEVICE_ID		XPAR_INTC_0_DEVICE_ID
#define UART_INT_IRQ_ID		XPAR_INTC_0_UARTPS_0_VEC_ID
#else
#define INTC		XScuGic
#define UART_DEVICE_ID		XPAR_XUARTPS_0_DEVICE_ID
#define INTC_DEVICE_ID		XPAR_SCUGIC_SINGLE_DEVICE_ID
#define UART_INT_IRQ_ID		XPAR_XUARTPS_1_INTR
#endif
/*
 * The following constant controls the length of the buffers to be sent
 * and received with the UART,
 */
#define TEST_BUFFER_SIZE	100

/************************** Variable Definitions ***************************/

class Test_lib_uart {
private:

public:
	static int TotalReceivedCount;
	static int StatTotalReceivedCount;
	static int TotalSentCount;
	static int TotalErrorCount;
	Test_lib_uart();
	virtual ~Test_lib_uart();
	int test_l_uart(void);
	int UartPsIntrExample(INTC *IntcInstPtr, XUartPs *UartInstPtr, u16 DeviceId,
			u16 UartIntrId);

	XUartPs UartPs; /* Instance of the UART Device */
	INTC InterruptController; /* Instance of the Interrupt Controller */

	/*
	 * The following buffers are used in this example to send and receive data
	 * with the UART.
	 */
	u8 SendBuffer[TEST_BUFFER_SIZE]; /* Buffer for Transmitting Data */
	u8 RecvBuffer[TEST_BUFFER_SIZE]; /* Buffer for Receiving Data */

	/*
	 * The following counters are used to determine when the entire buffer has
	 * been sent and received.
	 */

	static void Handler(void *CallBackRef, u32 Event, unsigned int EventData);
	int SetupInterruptSystem(INTC *IntcInstancePtr, XUartPs *UartInstancePtr,
			u16 UartIntrId);
	int getTotalReceivedCount() {
		return Test_lib_uart::TotalReceivedCount;
	}
	;
	int getTotalSentCount() {
			return Test_lib_uart::TotalSentCount;
		}
		;
	static void incrTotalErrorCount() {
		Test_lib_uart::TotalErrorCount++;
	}
	;
	static void setTotalSentCount(int t) {
			Test_lib_uart::TotalSentCount = t;
		}
		;
	static void setTotalReceivedCount(int t) {
		Test_lib_uart::TotalReceivedCount = t;
		;
	}
	;
	// static member function

};

#endif /* SRC_TESTLIBUART_H_ */
