/////////////////////////////////////////////////////////////////////
// MainWindow.xaml.cs                                              //
// ver 1.0                                                         //
// Yuhan Liu, CSE687 - Object Oriented Design, Spring 2019         //
/////////////////////////////////////////////////////////////////////
/*
 * Package Operations:
 * --------------------------------------------------------------------
 *  This package defines the GUI using MainWindow.xaml file which is compiled
 *  to a working GUI saving you the effort of programatically creating GUIs.
 *  This package depends on Shim project, if Shim project is NOT built then
 *  Shim.dll does not exist and therefore you'll get Intellisense error saying
 *  you have missing reference. Do not worry about the error, once Shim project
 *  is successfully built this will build and run.
 *
 * Required Files:
 * --------------------------------------------------------------------
 * MainWindow.xaml  
 * MainWindow.xaml.cs
 * Shim.dll
 * 
 * Maintenance History:
 * ver 1.0 : 11 Apr 2019
 *  -first release
 * 
 */
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.IO;

namespace WPF_CLI
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        private string WDirectory { get; set; }
        private string Patterns { get; set; }
        private string Regex { get; set; }
        private string WDirectory_out { get; set; }

        /* -----< MainWindow constructor - Do not modify >-------------------*/
        public MainWindow()
        {
            InitializeComponent();
        }

        /*---<Window_Loaded event handler>---*/
        private void Window_Loaded(object sender, RoutedEventArgs e)
        {
            WDirectory = "../../../";
            WDirectory = Path.GetFullPath(WDirectory);
            Patterns = "*.h *.cpp";
            Regex = "[A-W].*";
            WDirectory_out = "../../../convertedPages";
            WDirectory_out = Path.GetFullPath(WDirectory_out);
            txtPath.Text = WDirectory;
            txtOutPath.Text = WDirectory_out;
            txtPatterns.Text = Patterns;
            txtRegex.Text = Regex;
            Shim shimWindow = new Shim();
            shimWindow.requires();
        }

        /*---<btnBrowse_Click event handler>---*/
        private void btnBrowse_Click(object sender, RoutedEventArgs e)
        {
            System.Windows.Forms.FolderBrowserDialog dialog = new System.Windows.Forms.FolderBrowserDialog();
            if (dialog.ShowDialog() == System.Windows.Forms.DialogResult.OK)
            {
                WDirectory = dialog.SelectedPath;
                txtPath.Text = WDirectory;
            }
        }
        //Attention!!!!Shim Problem
        /*---<btnPublish_Click event handler>---*/
        private void btnPublish_Click(object sender, RoutedEventArgs e)
        {
            txtProgress.Text = "Converting: Sending Cmd Line:";
            List<string> args = new List<string>();
            args.Add(WDirectory);
            if(Patterns != null)
            {
                var patt = Patterns.Split(' ');
                foreach (var p in patt)
                    args.Add(p);
            }
            if (Regex != null)
            {
                var reg = Regex.Split(' ');
                foreach (var r in reg)
                    args.Add(r);
            }
            if (cbRecurse.IsChecked == true)
                args.Add("/s");
            txtProgress.Text = "Converting: Setting Directory Explorer";
            List<string> names_ = new List<string>();
            Shim shim = new Shim();
            shim.Init(args);
            txtProgress.Text = "Converting: ";
            shim.treeSet(WDirectory_out);
            names_ = shim.getname();
            lstConverted.Items.Clear();
            foreach (var n in names_)
                lstConverted.Items.Add(n);      
            //shim.publisher(WDirectory_out);
            txtProgress.Text = "Converting Completed.";
        }

        /*---<txtPath_TextChanged event handler>---*/
        //everytime when txtPath is changed, this event will be triggered
        private void txtPath_TextChanged(object sender, TextChangedEventArgs e)
        {
            lstFiles.Items.Clear();
            lstFiles.Items.Add("[..]");

            var dirs = Directory.GetDirectories(WDirectory);
            foreach (var dir in dirs)
            {
                string dirName = "[" + Path.GetFileName(dir) + "]";
                lstFiles.Items.Add(dirName);
            }

            List<string> filesMatchingPatterns = new List<string>();
            if (Patterns != null)
            {
                var patterns = Patterns.Split(' ');
                foreach (var patt in patterns)
                    filesMatchingPatterns.AddRange(Directory.GetFiles(WDirectory, patt));
            }
            else
            {
                filesMatchingPatterns = Directory.GetFiles(WDirectory).ToList();
            }
            foreach (var file in filesMatchingPatterns) lstFiles.Items.Add(Path.GetFileName(file));
        }

        /*---<lstFiles_MouseDoubleClick event handler>---*/
        private void lstFiles_MouseDoubleClick(object sender, MouseButtonEventArgs e)
        {
            if (lstFiles.SelectedIndex == -1) return;

            string selectedItem = lstFiles.SelectedItem.ToString();
            selectedItem = selectedItem.Substring(1, selectedItem.Length - 2);
            selectedItem = Path.Combine(WDirectory, selectedItem);
            selectedItem = Path.GetFullPath(selectedItem);

            if (!Directory.Exists(selectedItem)) return;

            WDirectory = selectedItem;
            txtPath.Text = selectedItem;
        }

        /*---<TxtOutPath_TextChanged event handler>---*/
        private void TxtOutPath_TextChanged(object sender, TextChangedEventArgs e)
        {
            WDirectory_out = txtOutPath.Text.ToString();
        }

        /*---<BtnOutBrowse_Click event handler>---*/
        private void BtnOutBrowse_Click(object sender, RoutedEventArgs e)
        {
            System.Windows.Forms.FolderBrowserDialog dialog_out = new System.Windows.Forms.FolderBrowserDialog();
            if (dialog_out.ShowDialog() == System.Windows.Forms.DialogResult.OK)
            {
                WDirectory_out = dialog_out.SelectedPath;
                txtOutPath.Text = WDirectory_out;
            }
        }

        /*---<LstConverted_MouseDoubleClick event handler>---*/
        private void LstConverted_MouseDoubleClick(object sender, MouseButtonEventArgs e)
        {
            if (lstConverted.SelectedIndex == -1) return;
            string selectedItem = lstConverted.SelectedItem.ToString();
            selectedItem = Path.Combine(WDirectory_out, selectedItem);
            selectedItem = selectedItem + ".html";
            System.Diagnostics.Process.Start(selectedItem);
        }

        /*---<TxtRegex_TextChanged event handler>---*/
        private void TxtRegex_TextChanged(object sender, TextChangedEventArgs e)
        {
            Regex = txtRegex.Text.ToString();
        }

        /*---<TxtPatterns_TextChanged event handler>---*/
        private void TxtPatterns_TextChanged(object sender, TextChangedEventArgs e)
        {
            Patterns = txtPatterns.Text.ToString();
        }
    }
}
