#include <Arduino.h>
#include <string.h>
#include <stdio.h>
#include "msgqueue.h"

MsgQueue::MsgQueue(uint8_t _display_width):
  displayed_at(millis()), display_width(_display_width), message_count(0), message_pos(0), message_size(0), queue_processing(true)
{
}

void MsgQueue::clear(void)
{
  memset(messages, 0, MSGQUEUE_MAX_MESSAGE_LEN * MSGQUEUE_MAX_MESSAGES);
  message_count = 0;
  message_pos   = 0;
  queue_processing = false;
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

bool MsgQueue::addMessage(const char * msg, va_list args)
{
  if (message_count == MSGQUEUE_MAX_MESSAGES) { return false; }
  if (strlen(msg) >= MSGQUEUE_MAX_MESSAGE_LEN) { return false; }

  memset(messages[message_count], 0, MSGQUEUE_MAX_MESSAGE_LEN);
  vsnprintf(messages[message_count], MSGQUEUE_MAX_MESSAGE_LEN, msg, args);

  message_count++;
  queue_processing = true;
  return true;
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

    strncpy(view, &(messages[0][message_pos]), display_width);
    view[display_width] = '\0';

    message_pos += display_width;
    if (message_pos >= message_size) { dropMessage(); }
  }

  displayed_at = millis();

  return view;
}
