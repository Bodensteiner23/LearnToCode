void sendMsg(uint16_t id, uint8_t dlc, uint8_t *data);
/*
void sendMsg(uint16_t id, uint8_t dlc, uint8_t *data){
  FDCAN_TxHeaderTypeDef TxHeader = { 0 };
  TxHeader.Identifier = id;
  TxHeader.IdType = FDCAN_STANDARD_ID;
  TxHeader.TxFrameType = FDCAN_DATA_FRAME;
  TxHeader.DataLength = dlc << 16;
  HAL_FDCAN_AddMessageToTxFifoQ(&hfdcan1, &TxHeader, data);
}
*/

#define PAGE_SIZE 4096
#define BASE_ADDRESS  0x08000000

#define BOOT_RX_ID (*((__IO uint32_t*) (BASE_ADDRESS + 3 * PAGE_SIZE + 5 * 4)))
#define BOOT_TX_ID (*((__IO uint32_t*) (BASE_ADDRESS + 3 * PAGE_SIZE + 6 * 4)))

typedef struct {
  uint32_t StdId;
  uint8_t Data[8];
  uint8_t DLC;
} CanRxMsg;

//Commands which the bootloader accepts
typedef enum {
  cmd_reset,
  cmd_getState,
  cmd_startBL,
  cmd_startApp,
  cmd_erase,
  cmd_read,
  cmd_write,
  cmd_resetAdr,
  cmd_verifyCRC,
  cmd_readParam,
  cmd_writeParam,
  cmd_saveParam,
} cmd_t;

//Replies the bootloader might answer with
typedef enum {
  rply_okay, rply_done, rply_error,
} rply_t;

void boot_CANHandler(CanRxMsg rxmsg) {
  if (rxmsg.StdId == BOOT_RX_ID ||
      rxmsg.StdId == 0x7DF) {
    switch(rxmsg.Data[0]) {
    uint8_t TxData[8];
    case cmd_getState:
      TxData[0] = cmd_getState;
      TxData[1] = 0;
      sendMsg(BOOT_TX_ID, 2, TxData);
      break;
    case cmd_startBL:
      //Reset and jump to bootloader
      HAL_NVIC_SystemReset();
      break;
    case cmd_readParam:
      //Send back requested parameter
      if(rxmsg.DLC == 2) {
        TxData[0] = cmd_readParam;
        TxData[1] = rxmsg.Data[1];
        uint32_t* ptr = (uint32_t*) &TxData[2];
        *ptr = *(uint32_t*)(0x08003000 + rxmsg.Data[1] * 4); // TODO: Fix in boot.h
        sendMsg(BOOT_TX_ID, 6, TxData);
      } else { //Error
        TxData[0] = cmd_readParam;
        TxData[1] = rply_error;
        sendMsg(BOOT_TX_ID, 2, TxData);
      }
      break;
    default:
      ;
    }
  }
}
