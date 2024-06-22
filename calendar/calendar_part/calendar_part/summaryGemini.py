import google.generativeai as genai
import os


def get_api_key(file_path):
    # api키 보호를 위해 따로 저장 후 gitignore
    with open(file_path, 'r', encoding='utf-8') as file:
        return file.read().strip()


# 절대 경로를 사용하여 api_key.txt 파일 위치 지정
api_key_file = r'C:\Users\ktmth\source\repos\codinghaezo\combine_project\combine_project\api_key.txt'
api_key = get_api_key(api_key_file)
genai.configure(api_key=api_key)

# model = genai.GenerativeModel('gemini-pro')
model = genai.GenerativeModel('gemini-1.5-flash-latest')


def summarize_text(text):
    response = model.generate_content(f"{text}\n\n위 내용을 요약해 줘. 엔터로 구분해 줘. 간단한 설명도 덧붙여주고 조언도 해줘.")
    return response.text


def read_file(file_path):
    # reminders.txt 파일 읽기 (combine project)
    with open(file_path, 'r') as file:
        return file.read()


def write_file(file_path, text):
    # summary.txt 파일 쓰기 (combine project) - ANSI 인코딩 사용
    with open(file_path, 'w') as file:
        file.write(text)


def main():
    input_file_path = r'C:\Users\ktmth\source\repos\codinghaezo\combine_project\combine_project\reminders.txt'  # 입력 파일 위치
    output_file_path = r'C:\Users\ktmth\source\repos\codinghaezo\combine_project\combine_project\summary.txt'  # 출력 파일 위치 (위와 동일)

    text = read_file(input_file_path)
    summary = summarize_text(text)

    '''
    print("요약 결과:")
    print(summary)
    '''

    write_file(output_file_path, summary)


if __name__ == "__main__":
    main()
