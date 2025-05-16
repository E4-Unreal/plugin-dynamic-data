# PLUGIN_NAME

## 설치 방법

### 서브 모듈

1. 메인 프로젝트 `git` 저장소 열기
2. 플러그인 `git` 저장소를 메인 프로젝트 `git` 저장소에 서브 모듈로서 추가
    - git 저장소의 `하위 폴더`에 언리얼 프로젝트가 생성된 경우 `지역 상대 경로`: `언리얼_프로젝트_폴더_이름/Plugins/PLUGIN_NAME`
    - git 저장소의 `루트 폴더`에 언리얼 프로젝트가 생성된 경우 `지역 상대 경로`: `Plugins/PLUGIN_NAME`

### zip 파일

1. `zip` 파일 다운로드
2. 압축 해제 후 루트 폴더 이름을 `PLUGIN_NAME`으로 수정
3. 언리얼 프로젝트 `Plugins` 폴더로 `PLUGIN_NAME` 붙여넣기
