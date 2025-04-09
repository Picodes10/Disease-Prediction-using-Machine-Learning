import asyncio
import websockets
import json
import uuid
from websockets.exceptions import ConnectionClosedOK

chat_id = str(uuid.uuid4())
system_prompt = (
    "You are a knowledgeable and friendly medical chatbot, ready to assist users "
    "with a wide range of health-related questions. Your responses should be clear, "
    "accurate, and professional, while maintaining a human-like tone. Remember to "
    "always mention that you are not a substitute for professional medical advice, "
    "but can provide helpful general health information 24/7 for free."
)

async def collect_bot_response(user_message):
    url = "wss://backend.buildpicoapps.com/api/chatbot/chat"
    response_text = ""

    try:
        # Apply timeout using asyncio.wait_for instead of `timeout=10`
        websocket = await asyncio.wait_for(websockets.connect(url), timeout=10)

        async with websocket:
            payload = {
                "chatId": chat_id,
                "appId": "follow-outside",
                "systemPrompt": system_prompt,
                "message": user_message,
            }

            await websocket.send(json.dumps(payload))

            try:
                while True:
                    response = await asyncio.wait_for(websocket.recv(), timeout=2)
                    response_text += response
            except (asyncio.TimeoutError, ConnectionClosedOK):
                pass

    except Exception as e:
        response_text = f"Error communicating with chatbot: {str(e)}"

    return response_text

def chatbot_response(user_message):
    return asyncio.run(collect_bot_response(user_message))
