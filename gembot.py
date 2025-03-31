import google.generativeai as genai
import os

# Set up Gemini API key
os.environ["GOOGLE_API_KEY"] = "AIzaSyCgF0c7AB5FYvqi1LSk-VQiPEp7w8eUVv8"
genai.configure(api_key=os.environ["GOOGLE_API_KEY"])

# Define system prompt for disease information
SYSTEM_PROMPT = """You are a medical information assistant specializing in disease information. 
Your role is to provide accurate, helpful information about:
1. Disease symptoms and signs
2. Common causes and risk factors
3. Available treatments and medications
4. Prevention strategies
5. When to seek medical attention

Please note that you should:
- Always emphasize that you are an AI assistant and not a replacement for professional medical advice
- Encourage users to consult healthcare providers for diagnosis and treatment
- Provide general information only, not specific medical advice
- Be clear and concise in your responses
- Use medical terminology appropriately but explain complex terms
- Include relevant statistics when available
- Mention potential complications and warning signs

If the user's question is unclear or too vague, ask for clarification."""

# Define chatbot function
def chatbot_response(user_input):
    try:
        model = genai.GenerativeModel("gemini-1.5-pro")
        
        # Combine system prompt with user input
        prompt = f"{SYSTEM_PROMPT}\n\nUser Question: {user_input}"
        
        response = model.generate_content(prompt)
        return response.text
    except Exception as e:
        return f"I apologize, but I encountered an error: {str(e)}. Please try again later."

# Example interaction
if __name__ == "__main__":
    print("Medical Information Assistant (Type 'exit' to quit)")
    print("Ask me about diseases, symptoms, treatments, or prevention strategies.")
    while True:
        user_input = input("\nYou: ")
        if user_input.lower() == "exit":
            break
        response = chatbot_response(user_input)
        print("\nAssistant:", response)
