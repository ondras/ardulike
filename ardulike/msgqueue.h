#ifndef __ARDULIKE_MSGQUEUE_H__
#define __ARDULIKE_MSGQUEUE_H__

#include <inttypes.h>
#include <stdarg.h>

#include "constants.h"

#define MSGQUEUE_MAX_MESSAGES      3
#define MSGQUEUE_MAX_MESSAGE_LEN  31
#define MSGQUEUE_ROTATE_TIME_MS 1500

class MsgQueue {
  private:
    uint32_t displayed_at;
    uint8_t  display_width;
    uint8_t  message_count;

    uint8_t  message_pos, message_size;

    char messages[MSGQUEUE_MAX_MESSAGES][MSGQUEUE_MAX_MESSAGE_LEN + 1];
    char view[SCREEN_COLS + 1];
    bool queue_processing;

    void dropMessage(void);
  public:
    MsgQueue(uint8_t _display_width);
    bool   addMessage(const char * msg, va_list args);
    bool   viewChanged(void);
    char * getView(void);
    void   clear(void);
    void   setDisplayWidth(uint8_t _display_width);
};

#endif
