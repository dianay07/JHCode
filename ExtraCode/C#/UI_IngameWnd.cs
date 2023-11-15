using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using UnityEngine.SceneManagement;

public class UI_IngameWnd : UI_Base
{
    [SerializeField] UI_Obj ui_inven;                                

    // 순서대로 담을 스택
    [SerializeField] Stack<GameObject> PopupUI_Stack = new Stack<GameObject>();

    // 단축키 지정
    void Update()
    {
        if (Input.GetKeyDown(KeyCode.I)) { }
        else if (Input.GetKeyDown(KeyCode.Q)) { }
        else if (Input.GetKeyDown(KeyCode.Escape){ }


    }

    // UI 닫기
    public void CloseOrEnd() 
    {
        // 1개 이상 UI가 켜져있으면 삭제
        if (PopupUI_Stack.Count != 0)
            PopUIObj();
        // 0개일때 눌렷을경우
        else              
        {

        }
    }

    // 인벤토리 키고 끄기
    public void inventoryUIOpen()
    {
        // 안켜져있을때
        if (ui_inven.isActiveAndEnabled == false) 
        {
            //SwitchActive(ui_inven.transform.parent.transform);
            //ui_inven.refreshInven();      // UI 새로그리기
        }
        else
        {
            // 스택안에 모든 UI 삭제
            foreach (var item in PopupUI_Stack)
            {
                Destroy(item);
            }
            PopupUI_Stack.Clear();
            SwitchActive(ui_inven.transform.parent.transform);
        }
    }

    // 생성된 UI 오브젝트 추가
    public GameObject PushUIObj(GameObject obj)
    {
        // 켜져있으면
        PopupUI_Stack.Push(obj);

        return obj;
    }

    // 맨위 UI 삭제
    public GameObject PopUIObj()
    {
        GameObject destroyObj = PopupUI_Stack.Pop();
        Destroy(destroyObj);

        return destroyObj;
    }
}
