using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Parser : MonoBehaviour
{
    // 어떤 종류의 데이터 액셀 읽기
    public Data[] DataParse(string fileName)
    {
        // 데이터 덩어리를 리스트로 생성
        List<Data> datalist = new List<Data>();
        TextAsset csvData = Resources.Load<TextAsset>("Data/" + fileName);

        // 띄어쓰기를 기준으로 나누기
        string[] data = csvData.text.Split(new char[] { '\n' });

        for (int i = 1; i < data.Length; i++)
        {
            // 대사같은 거면 , 단위로 나누기
            //string[] row = data[i].Split(new char[] { ',' });

            // Data 객체 생성 후 내용 설정
            Data item = new Data();
            //Data.name = row[0];
            //Data.price = Double.Parse(row[1]);
            //Data.id = Int32.Parse(row[3]);
            //Data.desc = row[4];
            //Data.itemEffect = float.Parse(row[5]);
            //Data.effectdesc = row[6];

            datalist.Add(item);
            GameManager.dbManager.giveinfo.itemlist.Add(item);
        }

        return itemlist.ToArray();
    }
}

