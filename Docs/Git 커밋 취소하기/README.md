# Git 커밋 취소하기

이 문서는 Git 커밋을 취소하는 방법에 대한 문서입니다.

> ※ git commit은 신중하게 이루어져야 합니다.

<br><br>


## Git 커밋 취소하기 

Git 커밋은 항상 신중하게 이루어져야 합니다. 하지만, 어쩌다보면 실수가 날 수도 있습니다. 이러한 실수를 수습하기 위한 방법은 두 가지 경우에 따라 약간 달라집니다.

### 원격 저장소에 push 하지 않은 경우

원격 저장소에 push 하지 않은 경우는 수습하기 어렵지 않습니다. CMD 혹은 Git Bash에 다음 명령어를 입력합니다.
- 변경 이력이 존재하는 파일을 Staged 상태로 할 경우
    ```bash
    $ git reset --soft HEAD^
    ```
- 변경 이력이 존재하는 파일을 Unstaged 상태로 할 경우
    ```bash
    $ git reset --hard HEAD^
    ```

### 원격 저장소에 push 한 경우

원격 저장소에 push 한 경우는 수습하기 어렵습니다. 혼자 개인 프로젝트를 진행한다면 큰 문제가 발생할 가능성이 낮지만, 다른 사람과 함께 협업하고 있는 경우 문제가 발생할 수 있습니다.  

우선 [원격 저장소에 push 하지 않은 경우](#원격-저장소에-push-하지-않은-경우)의 방법대로 수행합니다.
다음으로, CMD 혹은 Git Bash에 다음 명령어를 입력합니다.

```bash
$ git push origin --force
```

위 명령어를 입력하면 강제로 push 하게 되므로 커밋을 변경할 수 있습니다.
<br><br>


## 참조
- [git add 취소하기, git commit 취소하기, git push 취소하기](https://gmlwjd9405.github.io/2018/05/25/git-add-cancle.html)