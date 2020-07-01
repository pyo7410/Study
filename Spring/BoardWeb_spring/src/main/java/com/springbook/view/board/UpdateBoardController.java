package com.springbook.view.board;

import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.RequestMapping;

import org.springframework.web.servlet.ModelAndView;
//import org.springframework.web.servlet.mvc.Controller;

import com.springbook.biz.board.BoardVO;
import com.springbook.biz.board.impl.BoardDAO;

/*
public class UpdateBoardController implements Controller {

	@Override
	public ModelAndView handleRequest(HttpServletRequest request, HttpServletResponse response) {
		System.out.println("�� ���� ó��");

		// 1. ����� �Է� ���� ����
		// ����� �Է� �����Ϳ� �ѱ��� ���ԵǾ� ������, ����� �Է������� getParameter() �޼ҵ�� �������� �� �ѱ��� ������.
		// ���� ����� �Է� ������ �����ϱ� ���� �ݵ�� setCharacterEncoding() �޼ҵ�� �ѱ� ���ڵ� ó���� �ʿ��ϴ�.
		// request.setCharacterEncoding("EUC-KR");
		String title = request.getParameter("title");
		String content = request.getParameter("content");
		String seq = request.getParameter("seq");

		// 2. DB ���� ó��
		BoardVO vo = new BoardVO();
		vo.setTitle(title);
		vo.setContent(content);
		vo.setSeq(Integer.parseInt(seq));

		BoardDAO boardDAO = new BoardDAO();
		boardDAO.updateBoard(vo);

		// 3. ȭ�� �׺���̼�
		ModelAndView mav = new ModelAndView();
		mav.setViewName("redirect:getBoardList.do");
		return mav;
	}

}
*/
