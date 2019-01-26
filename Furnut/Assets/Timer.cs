using System;
using System.Collections;
using System.Collections.Generic;
using System.IO;
using UnityEngine;

public class Timer : MonoBehaviour {
    private StreamWriter _file;
    private DateTime _startTime;
    private int _iterations;
    public string fileName = "Unity (Release)";

    // Use this for initialization
    void Start () {
        _file = new StreamWriter(fileName);
        _file.WriteLine("Iteration,Runtime(ns)");
        _iterations = 0;
        _startTime = DateTime.UtcNow;
	}
	
	// Update is called once per frame
	void Update () {
        var runTime = DateTime.UtcNow - _startTime;

        _file.WriteLine(_iterations.ToString() + "," + runTime.Ticks * 100D);

        _iterations++;
        _startTime = DateTime.UtcNow;
	}

    private void OnDestroy()
    {
        if (_file != null)
        {
            _file.Flush();
            _file.Close();
        }
    }
}
