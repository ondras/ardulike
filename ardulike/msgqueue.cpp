#include <Arduino.h>
#include "msgqueue.h"

MsgQueue::MsgQueue(uint8_t _display_width):
  display_width(_display_width), displayed_at(millis()), message_count(0), message_pos(0), message_size(0), queue_processing(true)
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
  queue_processing = true;
}

bool MsgQueue::viewChanged(void)
{
  return queue_processing && (millis() - displayed_at) > MSGQUEUE_ROTATE_TIME_MS;
}

char * MsgQueue::getView(void)
{
  if (message_count == 0) {
    memset(view, CHAR_SPACE, SCREEN_COLS);
    queue_processing = false;
  } else {
    message_size = strlen(messages[0]);

    snprintf(view, display_width + 1, "%s", &(messages[0][message_pos]));
    view[display_width] = '\0';

    message_pos += display_width;
    if (message_pos >= message_size) { dropMessage(); }
  }

  displayed_at = millis();

  return view;
}
