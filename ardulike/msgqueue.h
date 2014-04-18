#ifndef __ARDULIKE_MSGQUEUE_H__
#define __ARDULIKE_MSGQUEUE_H__

#include <inttypes.h>
#include "constants.h"

#define MSGQUEUE_MAX_MESSAGES      4
#define MSGQUEUE_MAX_MESSAGE_LEN  31
#define MSGQUEUE_ROTATE_TIME_MS 1500

class MsgQueue {
  private:
    uint16_t displayed_at;
    uint8_t  display_width;
    uint8_t  message_count;

    uint8_t  message_pos, message_size;

    char messages[MSGQUEUE_MAX_MESSAGES][MSGQUEUE_MAX_MESSAGE_LEN + 1];
    char view[SCREEN_COLS + 1];
    bool queue_processing;

    void dropMessage(void);
  public:
    MsgQueue(uint8_t _display_width);
    bool   addMessage(char * msg);
    bool   viewChanged(void);
    char * getView(void);
};

#endif
