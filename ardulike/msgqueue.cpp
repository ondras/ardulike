#include <Arduino.h>
#include "msgqueue.h"

MsgQueue::MsgQueue(uint8_t _display_width):
  display_width(_display_width), displayed_at(millis()), message_count(0), message_pos(0), message_size(0)
{
}

void MsgQueue::dropMessage(void)
{
  for (uint8_t i = 0; i < MSGQUEUE_MAX_MESSAGES - 1; i++) {
    memset(messages[i], 0, MSGQUEUE_MAX_MESSAGE_LEN);
    strncpy(messages[i], messages[i+1], MSGQUEUE_MAX_MESSAGE_LEN);
  }

  memset(messages[MSGQUEUE_MAX_MESSAGES - 1], 0, MSGQUEUE_MAX_MESSAGE_LEN);

  message_count--;
  message_pos = 0;
}

bool MsgQueue::addMessage(char * msg)
{
  if (message_count == MSGQUEUE_MAX_MESSAGES) { return false; }
  if (strlen(msg) >= MSGQUEUE_MAX_MESSAGE_LEN) { return false; }

  strncpy(messages[message_count], msg, MSGQUEUE_MAX_MESSAGE_LEN);
  messages[message_count][MSGQUEUE_MAX_MESSAGE_LEN] = '\0';

  message_count++;
}

uint8_t MsgQueue::getCount(void)
{
  return message_count;
}

bool MsgQueue::viewChanged(void)
{
  return message_count > 0 && (millis() - displayed_at) > MSGQUEUE_ROTATE_TIME_MS;
}

char * MsgQueue::getView(void)
{
  memset(view, CHAR_SPACE, SCREEN_COLS);

  if (message_count > 0) {
    message_size = strlen(messages[0]);

    // Drop the old message from the queue
    if (message_pos >= message_size) { dropMessage(); }

    snprintf(view, display_width + 1, "%s", &(messages[0][message_pos]));
    view[display_width] = '\0';

    message_pos += display_width;
  }

  displayed_at = millis();

  return view;
}
